import unittest  # No borrar esto!
from grafo import Grafo
from assignment_main import * # Modificar con el nombre de la api que se le entrega al alumno!

# Accede a las funciones del alumno desde el modulo assignment_main

def permutaciones(lista):
  return [lista[i:] + lista[:i] for i in range(len(lista))]

class TestMethods(unittest.TestCase):

  def test_grafo_vacio(self):
    g = Grafo(es_dirigido = False)
    self.assertEqual(diametro(g), 0)

  def test_unico_camino_maximo(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E', 'F'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'D')
    g.agregar_arista('A', 'C')
    g.agregar_arista('C', 'E')
    g.agregar_arista('E', 'D')
    g.agregar_arista('E', 'B')
    g.agregar_arista('D', 'F')
    self.assertEqual(diametro(g), 3)

  def test_multiples_caminos_maximos(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'D')
    g.agregar_arista('A', 'C')
    g.agregar_arista('C', 'E')
    g.agregar_arista('E', 'D')
    g.agregar_arista('E', 'B')
    self.assertEqual(diametro(g), 2)

  def test_multiples_caminos_maximos(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'D')
    g.agregar_arista('A', 'C')
    g.agregar_arista('C', 'E')
    g.agregar_arista('E', 'D')
    g.agregar_arista('E', 'B')
    self.assertEqual(diametro(g), 2)




if __name__=="__main__":unittest.main()