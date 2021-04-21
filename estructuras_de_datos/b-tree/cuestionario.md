# La situación de overflow...

- En la inserción (cuando el nodo no tiene lugar, se dice que se da de alta con overflow): se realiza un split. El split consiste en tomar el conjunto de elementos del nodo y el a agregar y generar dos nodos. Cada una con la mitad del todo y promoviendo la clave de valor medio a un nivel superior (que de no existir se genera uno nuevo con la clave promovida). Puede ocurrir que al promoverse una clave al nivel superior esta produzca un overflow en el mismo. En este caso se procederá a realizar un split en este nvvel superior. Si se debe hacer un split de la raiz, entonces el árbol crece en profundidad.

- Al haber overflow, podemos imaginar que se genera un “supernodo” (en realidad nunca llega a estar incluido en el árbol) con un elemento más. Luego tomamos el elemento del centro y ese elemento es el que se promociona al nivel superior. Los elementos que quedan a la izquierda irán a su hijo izquierdo y los que quedan a la derecha quedarán en su hijo derecho.

- Luego de un split, los nodos no hojas y no raíz tienen al menos los mínimos de descendientes por nodo

- Al producirse un overflow o underflow se realiza una redistribución, concatenación o split según corresponda.

# Si un árbol B admite hasta 50 claves por nodo, ¿hasta cuántos hijos podrá tener cada nodo?

Si tiene K claves, debe tener K+1 hijos, salvo la raíz y las hojas