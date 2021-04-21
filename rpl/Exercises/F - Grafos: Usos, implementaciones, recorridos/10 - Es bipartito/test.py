import unittest  # No borrar esto!
from grafo import Grafo
from assignment_main import es_bipartito # Modificar con el nombre de la api que se le entrega al alumno!

# Accede a las funciones del alumno desde el modulo assignment_main

class TestMethods(unittest.TestCase):

  def test_grafo_vacio(self):
    g = Grafo()
    self.assertEqual(es_bipartito(g), True)
  
  def test_grafo_2_vertices(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B'])
    g.agregar_arista('A', 'B')
    self.assertEqual(es_bipartito(g), True)

  def test_grafo_3_vertices_ciclo(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'C')
    g.agregar_arista('C', 'A')
    self.assertEqual(es_bipartito(g), False)

  def test_grafo_grande_bipartito(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E', 'F'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'D')
    g.agregar_arista('C', 'B')
    g.agregar_arista('C', 'F')
    g.agregar_arista('E', 'D')
    g.agregar_arista('E', 'F')
    self.assertEqual(es_bipartito(g), True)
  
  def test_grafo_grande_no_bipartito(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E', 'F'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'D')
    g.agregar_arista('C', 'B')
    g.agregar_arista('C', 'F')
    g.agregar_arista('E', 'D')
    g.agregar_arista('E', 'F')
    g.agregar_arista('D', 'F')
    self.assertEqual(es_bipartito(g), False)


if __name__=="__main__":unittest.main()