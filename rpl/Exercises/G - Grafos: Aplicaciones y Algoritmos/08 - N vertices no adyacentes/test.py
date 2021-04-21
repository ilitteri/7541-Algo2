import unittest  # No borrar esto!
from grafo import Grafo
from assignment_main import * # Modificar con el nombre de la api que se le entrega al alumno!

import itertools

# Accede a las funciones del alumno desde el modulo assignment_main

class TestMethods(unittest.TestCase):

  def test_grafo_completo_4_nodos(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'C')
    g.agregar_arista('A', 'D')
    g.agregar_arista('B', 'C')
    g.agregar_arista('B', 'D')
    g.agregar_arista('C', 'D')
    self.assertEqual(no_adyacentes(g, 2), False)

  def test_grafo_con_subset_de_3_A(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E', 'F'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'C')
    g.agregar_arista('B', 'D')
    g.agregar_arista('B', 'E')
    g.agregar_arista('C', 'F')
    self.assertEqual(no_adyacentes(g, 3), True)

  def test_grafo_con_subset_de_3_B(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E', 'F', 'G'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'C')
    g.agregar_arista('B', 'D')
    g.agregar_arista('B', 'E')
    g.agregar_arista('C', 'F')
    g.agregar_arista('E', 'G')
    g.agregar_arista('F', 'G')    
    self.assertEqual(no_adyacentes(g, 3), True)

  def test_grafo_con_subset_de_4(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'C')
    g.agregar_arista('B', 'D')
    g.agregar_arista('B', 'E')
    g.agregar_arista('C', 'F')
    g.agregar_arista('D', 'H')
    g.agregar_arista('E', 'H')
    g.agregar_arista('E', 'G')
    g.agregar_arista('F', 'G')
    self.assertEqual(no_adyacentes(g, 4), True)



if __name__=="__main__":unittest.main()