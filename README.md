# Sistema de Gestión de Biblioteca con Lista Enlazada Doble (DLL)

## Descripción del Problema

Este proyecto consiste en el desarrollo de un sistema de gestión de biblioteca utilizando una **lista enlazada doble (Doubly Linked List - DLL)**. Cada nodo representa un libro que contiene información básica como el título y el autor.

La estructura permite realizar operaciones eficientes como inserción, eliminación, búsqueda y actualización de libros.

---

## Requerimientos

### Clase `Libro`

**Atributos:**

* `titulo`: título del libro.
* `autor`: autor del libro.
* `siguiente`: puntero al siguiente nodo.
* `anterior`: puntero al nodo anterior.

**Constructor:**

* Inicializa el título y el autor.

---

### Clase `DLL`

**Atributos:**

* `head`: primer nodo de la lista.
* `tail`: último nodo de la lista.
* `size`: cantidad total de libros.

**Métodos:**

* `insertarEnOrden(Libro* nuevoLibro)`: inserta un libro en orden alfabético por título.
* `eliminarTodoExceptoTail()`: elimina todos los nodos excepto el último.
* `eliminarTodoExceptoHead()`: elimina todos los nodos excepto el primero.
* `buscarLibroPorTitulo(string titulo)`: busca un libro por título.
* `eliminarLibroPorTitulo(string titulo)`: elimina un libro por su título.
* `actualizarLibro(string tituloAntiguo, string nuevoTitulo, string nuevoAutor)`: actualiza un libro.
* `listarLibrosPorAutor(string autor)`: lista libros de un autor específico.
* `mostrarLibros()`: imprime todos los libros.
* `eliminarTodosLosLibros()`: elimina todos los nodos.
* `obtenerTamanio()`: retorna el tamaño de la lista.

---

## Implementación

### 1. Clases

Se implementaron dos clases principales:

* `Libro`: representa cada nodo.
* `DLL`: maneja la lista enlazada doble.

Cada método fue diseñado para cumplir con los requisitos del sistema, incluyendo manejo de punteros `head` y `tail`.

---

### 2. Driver (main)

En el archivo principal se realizan las siguientes operaciones:

1. Se crean cuatro libros.
2. Se insertan en la lista en orden alfabético.
3. Se muestran los libros.
4. Se actualiza un libro.
5. Se elimina un libro por título.
6. Se muestra la lista actualizada.
7. Se elimina todo excepto el último nodo.
8. Se muestra la lista.
9. Se eliminan todos los libros.
10. Se muestra el tamaño final.

---

## Salida Esperada

```
Libros en la biblioteca:

Título: Cien años de soledad, Autor: Gabriel García Márquez
Título: El amor en los tiempos del cólera, Autor: Gabriel García Márquez
Título: El Hobbit, Autor: J.R.R. Tolkien
Título: El Principito, Autor: Antoine de Saint-Exupéry

Actualizando 'El Hobbit' a 'El Hobbit: Una aventura inesperada'...

Libros en la biblioteca después de la actualización:

Título: Cien años de soledad, Autor: Gabriel García Márquez
Título: El amor en los tiempos del cólera, Autor: Gabriel García Márquez
Título: El Hobbit: Una aventura inesperada, Autor: J.R.R. Tolkien
Título: El Principito, Autor: Antoine de Saint-Exupéry

Eliminando 'El Principito'...

Libros en la biblioteca después de la eliminación:

Título: Cien años de soledad, Autor: Gabriel García Márquez
Título: El amor en los tiempos del cólera, Autor: Gabriel García Márquez
Título: El Hobbit: Una aventura inesperada, Autor: J.R.R. Tolkien

Eliminando todo excepto el tail...

Libros en la biblioteca después de eliminar todo excepto el tail:

Título: El Hobbit: Una aventura inesperada, Autor: J.R.R. Tolkien

Limpiando la biblioteca...

Número de libros en la biblioteca: 0
```

---

## Entregables

1. Todos los archivos desarrollados:

2. Screenshot de la salida en consola.

---

## Notas

* Se recomienda validar punteros nulos para evitar errores.
* Mantener el orden alfabético es clave en la inserción.
* Liberar memoria correctamente al eliminar nodos.

---

## Autor

Proyecto académico - Estructuras de Datos
