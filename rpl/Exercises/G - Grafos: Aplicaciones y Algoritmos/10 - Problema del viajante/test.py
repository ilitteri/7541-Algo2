import unittest  # No borrar esto!
from grafo import Grafo
from assignment_main import * # Modificar con el nombre de la api que se le entrega al alumno!

# Accede a las funciones del alumno desde el modulo assignment_main

def permutaciones(lista):
  return [lista[i:] + lista[:i] for i in range(len(lista))]

class TestMethods(unittest.TestCase):

  def test_grafo_completo_4_nodos(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D'])
    g.agregar_arista('A', 'B', 10)
    g.agregar_arista('A', 'C', 15)
    g.agregar_arista('A', 'D', 20)
    g.agregar_arista('B', 'C', 35)
    g.agregar_arista('B', 'D', 25)
    g.agregar_arista('C', 'D', 30)
    peso = viajante(g)

    self.assertEqual(peso, 80)

  def test_grafo_completo_5_nodos_A(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B', 12)
    g.agregar_arista('A', 'C', 10)
    g.agregar_arista('A', 'D', 19)
    g.agregar_arista('A', 'E', 8)
    g.agregar_arista('B', 'C', 3)
    g.agregar_arista('B', 'D', 7)
    g.agregar_arista('B', 'E', 2)
    g.agregar_arista('C', 'D', 6)
    g.agregar_arista('C', 'E', 20)
    g.agregar_arista('D', 'E', 4)
    peso = viajante(g)

    self.assertEqual(peso, 32)

  def test_grafo_completo_5_nodos_B(self):
    g = Grafo(es_dirigido = False, vertices_init=['A', 'B', 'C', 'D', 'E'])
    g.agregar_arista('A', 'B', 14)
    g.agregar_arista('A', 'C', 15)
    g.agregar_arista('A', 'D', 4)
    g.agregar_arista('A', 'E', 9)
    g.agregar_arista('B', 'C', 18)
    g.agregar_arista('B', 'D', 5)
    g.agregar_arista('B', 'E', 13)
    g.agregar_arista('C', 'D', 19)
    g.agregar_arista('C', 'E', 10)
    g.agregar_arista('D', 'E', 12)
    peso = viajante(g)

    self.assertEqual(peso, 46)




if __name__=="__main__":unittest.main()