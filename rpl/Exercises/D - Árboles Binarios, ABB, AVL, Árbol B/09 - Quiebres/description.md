Definimos como quiebre en un árbol binario cuando ocurre que:
* un hijo derecho tiene un solo hijo, y es el izquierdo
* un hijo izquierdo tiene un solo hijo, y es el derecho

Implementar una primitiva para el árbol binario size_t ab_quiebres(const ab_t*) que, dado un árbol binario, nos devuelva la cantidad de quiebres que tiene. La primitiva no debe modificar el árbol.