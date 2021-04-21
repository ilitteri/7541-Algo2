import unittest  # No borrar esto!
from grafo import Grafo
from assignment_main import * # Modificar con el nombre de la api que se le entrega al alumno!

# Accede a las funciones del alumno desde el modulo assignment_main

class TestMethods(unittest.TestCase):

  def test_grafo_vertices_vacio(self):
    g = Grafo(es_dirigido = False)
    self.assertEqual(grado_vertices(g), {})
  
  def test_grado_vertices_conexo(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'C')
    g.agregar_arista('A', 'D')
    g.agregar_arista('B', 'D')
    g.agregar_arista('B', 'C')
    grados = grado_vertices(g)
    self.assertEqual(grados['A'], 3)
    self.assertEqual(grados['B'], 3)
    self.assertEqual(grados['C'], 2)
    self.assertEqual(grados['D'], 2)
  
  def test_grado_vertices_no_conexo(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('A', 'C')
    g.agregar_arista('B', 'C')
    g.agregar_arista('E', 'D')
    grados = grado_vertices(g)
    self.assertEqual(grados['A'], 2)
    self.assertEqual(grados['B'], 2)
    self.assertEqual(grados['C'], 2)
    self.assertEqual(grados['D'], 1)
    self.assertEqual(grados['D'], 1)

  def test_grado_salida_conexo(self):
    g = Grafo(es_dirigido = True, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'C')
    g.agregar_arista('B', 'D')
    g.agregar_arista('D', 'A')
    grados = grado_salida(g)
    self.assertEqual(grados['A'], 1)
    self.assertEqual(grados['B'], 2)
    self.assertEqual(grados['C'], 0)
    self.assertEqual(grados['D'], 1)
    self.assertEqual(grados['E'], 0)

  def test_grado_salida_no_conexo(self):
    g = Grafo(es_dirigido = True, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'C')
    g.agregar_arista('C', 'A')
    g.agregar_arista('E', 'D')
    g.agregar_arista('D', 'E')
    grados = grado_salida(g)
    self.assertEqual(grados['A'], 1)
    self.assertEqual(grados['B'], 1)
    self.assertEqual(grados['C'], 1)
    self.assertEqual(grados['D'], 1)
    self.assertEqual(grados['E'], 1)

  def test_grado_entrada_conexo(self):
    g = Grafo(es_dirigido = True, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'C')
    g.agregar_arista('B', 'D')
    g.agregar_arista('D', 'A')
    grados = grado_entrada(g)
    self.assertEqual(grados['A'], 1)
    self.assertEqual(grados['B'], 1)
    self.assertEqual(grados['C'], 1)
    self.assertEqual(grados['D'], 1)
    self.assertEqual(grados['E'], 0)
  
  def test_grado_entrada_no_conexo(self):
    g = Grafo(es_dirigido = True, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B')
    g.agregar_arista('B', 'C')
    g.agregar_arista('C', 'A')
    g.agregar_arista('E', 'D')
    g.agregar_arista('D', 'E')
    grados = grado_salida(g)
    self.assertEqual(grados['A'], 1)
    self.assertEqual(grados['B'], 1)
    self.assertEqual(grados['C'], 1)
    self.assertEqual(grados['D'], 1)
    self.assertEqual(grados['E'], 1)



if __name__=="__main__":unittest.main()