import unittest  # No borrar esto!
import timeout_decorator
import assignment_main # Modificar con el nombre de la api que se le entrega al alumno!

# Accede a las funciones del alumno desde el modulo assignment_main


class TestMethods(unittest.TestCase):

  @timeout_decorator.timeout(5)  # segundos
  def test_2_es_par(self):
    self.assertTrue(assignment_main.es_par(2))

  def test_8_es_par(self):
    self.assertTrue(assignment_main.es_par(8))
  
  def test_9_es_impar(self):
    self.assertFalse(assignment_main.es_par(9))
  
  def test_0_es_par(self):
    self.assertTrue(assignment_main.es_par(0))
    


if __name__=="__main__":unittest.main()