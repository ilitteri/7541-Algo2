import unittest  # No borrar esto!
from grafo import Grafo
from assignment_main import * # Modificar con el nombre de la api que se le entrega al alumno!

# Accede a las funciones del alumno desde el modulo assignment_main

def permutaciones(lista):
  return [lista[i:] + lista[:i] for i in range(len(lista))]

class TestMethods(unittest.TestCase):

  def test_grafo_vacio(self):
    g = Grafo(es_dirigido = False)
    self.assertEqual(es_conexo(g), True)

  def test_grafo_conexo(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'C')
    g.agregar_arista('C', 'A')
    g.agregar_arista('C', 'D')
    g.agregar_arista('B', 'E')
    self.assertEqual(es_conexo(g), True)

  def test_grafo_conexo_circular(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'C')
    g.agregar_arista('C', 'D')
    g.agregar_arista('D', 'E')
    g.agregar_arista('E', 'A')
    self.assertEqual(es_conexo(g), True)

  def test_grafo_no_conexo(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E', 'F'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'C')
    g.agregar_arista('C', 'A')
    g.agregar_arista('C', 'D')
    g.agregar_arista('E', 'F')
    self.assertEqual(es_conexo(g), False)



if __name__=="__main__":unittest.main()