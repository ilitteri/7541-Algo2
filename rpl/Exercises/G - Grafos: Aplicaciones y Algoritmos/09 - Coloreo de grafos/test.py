import unittest  # No borrar esto!
from grafo import Grafo
from assignment_main import * # Modificar con el nombre de la api que se le entrega al alumno!

# Accede a las funciones del alumno desde el modulo assignment_main

def permutaciones(lista):
  return [lista[i:] + lista[:i] for i in range(len(lista))]

class TestMethods(unittest.TestCase):

  def test_grafo_vacio(self):
    g = Grafo(es_dirigido = False)
    self.assertEqual(colorear(g, 1), True)

  def test_grafo_bipartito(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E', 'F'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'D')
    g.agregar_arista('C', 'B')
    g.agregar_arista('C', 'F')
    g.agregar_arista('E', 'D')
    g.agregar_arista('E', 'F')
    self.assertEqual(colorear(g, 2), True)

  def test_grafo_no_bipartito(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E', 'F'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'D')
    g.agregar_arista('C', 'B')
    g.agregar_arista('C', 'F')
    g.agregar_arista('E', 'D')
    g.agregar_arista('E', 'F')
    g.agregar_arista('D', 'F')
    self.assertEqual(colorear(g, 2), False)

  def test_grafo_coloreable_con_3_colores(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'D')
    g.agregar_arista('B', 'C')
    g.agregar_arista('D', 'C')
    g.agregar_arista('A', 'C')
    self.assertEqual(colorear(g, 3), True)

  def test_grafo_no_coloreable_con_3_colores(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'D')
    g.agregar_arista('B', 'C')
    g.agregar_arista('D', 'C')
    g.agregar_arista('A', 'C')
    g.agregar_arista('A', 'E')
    g.agregar_arista('B', 'E')
    g.agregar_arista('C', 'E')
    self.assertEqual(colorear(g, 3), False)

  def test_grafo_coloreable_con_4_colores(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'D')
    g.agregar_arista('B', 'C')
    g.agregar_arista('D', 'C')
    g.agregar_arista('A', 'C')
    g.agregar_arista('A', 'E')
    g.agregar_arista('B', 'E')
    g.agregar_arista('C', 'E')
    self.assertEqual(colorear(g, 4), True)



if __name__=="__main__":unittest.main()