import unittest  # No borrar esto!
from grafo import Grafo
from assignment_main import * # Modificar con el nombre de la api que se le entrega al alumno!

# Accede a las funciones del alumno desde el modulo assignment_main

class TestMethods(unittest.TestCase):

  def test_grafo_vacio(self):
    g = Grafo(es_dirigido = False)
    self.assertEqual(obtener_orden(g), [])

  def test_grafo_lista_enlazada(self):
    g = Grafo(es_dirigido = True, vertices_init=['A', 'B', 'C', 'D'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'C')
    g.agregar_arista('C', 'D')
    orden = obtener_orden(g)
    self.assertTrue(orden == ['A', 'B', 'C', 'D'])


  def test_grafo_conexo(self):
    g = Grafo(es_dirigido = True, vertices_init=['A', 'B', 'C', 'D'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'C')
    g.agregar_arista('C', 'D')
    g.agregar_arista('B', 'D')
    orden = obtener_orden(g)
    self.assertTrue(orden == ['A', 'B', 'C', 'D'] or orden == ['A', 'C', 'B', 'D'])

  def test_grafo_no_conexo(self):
    g = Grafo(es_dirigido = True, vertices_init=['A', 'B', 'C', 'D'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('C', 'D')
    orden = obtener_orden(g)
    self.assertTrue(orden in [['A', 'B', 'C', 'D'], ['C', 'D', 'A', 'B'], ['A', 'C', 'B', 'D'], ['A', 'C', 'D', 'B']])




if __name__=="__main__":unittest.main()