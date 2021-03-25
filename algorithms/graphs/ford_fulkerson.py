def actualizar_grafo_residual(grafo_residual, u, v, valor):
    # Obtengo el peso anterior
    peso_anterior = grafo_residual.peso(u, v)
    # Si la arista tiene el mismo peso, entonces la saco.
    if peso_anterior == valor:
        grafo_residual.remover_arista(u, v)
    # Sino, le cambio el peso
    else:
        grafo_residual.cambiar_peso(u, v, peso_anterior - valor)
    # Si no existe la arista de retorno, la creo.
    if not grafo_residual.son_adyacentes(v, u):
        grafo_residual.agregar_arista(v, u, valor)
    # Sino, le cambio el peso.
    else:
        grafo_residual.cambiar_peso(v, u, peso_anterior + valor)

def flujo(grafo, s, t):
    # Inicializamos el flujo de cada arista en 0.
    flujo = {}
    for v in grafo:
        for w in grafo.adyacentes(v):
            flujo[(v, w)] = 0
    # Creamos una copia del grafo original.
    grafo_residual = copiar(grafo)
    # Mientras haya un camino en la red residual,
    while (camino = obtener_camino(grafo_residual, s, t)) is not None:
        # Actualizamos el flujo acorde al camino.
        capacidad_residual_camino = min_peso(grafo, camino)
        for i in range(1, len(camino)):
            # Si la arista pertenece al grafo original se trata de una arista
            # a la que le queremos aumentar el flujo.
            if camino[i] in grafo.adyacentes(camino[i-1]):
                flujo[(camino[i-1], camino[i])] += capacidad_residual_camino
                actualizar_grafo_residual(grafo_residual, camino[i-1], camino[i], capacidad_residual_camino)
            # Sino se trata de una arista de retorno, y lo queremos disminuir
            # el flujo para aumentarlo globalmente.
            else:
                flujo[(camino[i-1], camino[i])] -= capacidad_residual_camino
                actualizar_grafo_residual(grafo_residual, camino[i], camino[i-1], capacidad_residual_camino)
    # Devolvemos el flujo
    return flujo