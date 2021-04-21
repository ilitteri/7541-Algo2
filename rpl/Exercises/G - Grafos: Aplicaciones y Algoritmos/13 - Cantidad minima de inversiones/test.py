import unittest  # No borrar esto!
from grafo import Grafo
from assignment_main import * # Modificar con el nombre de la api que se le entrega al alumno!

# Accede a las funciones del alumno desde el modulo assignment_main

def permutaciones(lista):
  return [lista[i:] + lista[:i] for i in range(len(lista))]

class TestMethods(unittest.TestCase):

  def test_sin_inversiones(self):
    g = Grafo(es_dirigido = True, vertices_init=['0', '1', '2', '3', '4', '5', '6'])
    g.agregar_arista('0', '1')
    g.agregar_arista('1', '2')
    g.agregar_arista('2', '3')
    g.agregar_arista('3', '6')
    g.agregar_arista('6', '4')
    g.agregar_arista('4', '5')
    g.agregar_arista('5', '1')
    inversiones = minimas_inversiones(g, '0', '6')

    self.assertEqual(inversiones, 0)


  def test_con_2_inversiones(self):
    g = Grafo(es_dirigido = True, vertices_init=['0', '1', '2', '3', '4', '5', '6'])
    g.agregar_arista('0', '1')
    g.agregar_arista('2', '1')
    g.agregar_arista('2', '3')
    g.agregar_arista('6', '3')
    g.agregar_arista('6', '4')
    g.agregar_arista('4', '5')
    g.agregar_arista('5', '1')
    inversiones = minimas_inversiones(g, '0', '6')

    self.assertEqual(inversiones, 2)

  def test_con_1_inversion(self):
    g = Grafo(es_dirigido = True, vertices_init=['0', '1', '2', '3', '4', '5'])
    g.agregar_arista('0', '1')
    g.agregar_arista('1', '2')
    g.agregar_arista('3', '2')
    g.agregar_arista('3', '1')
    g.agregar_arista('3', '4')
    g.agregar_arista('3', '5')
    inversiones = minimas_inversiones(g, '0', '5')

    self.assertEqual(inversiones, 1)




if __name__=="__main__":unittest.main()