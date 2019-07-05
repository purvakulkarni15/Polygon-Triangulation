# Polygon-Triangulation

### Ear-Clipping Method

Ear Clipping triangulation method is all about finding an ear in the polygon thereby removing the ear vertex and repeating the process
for the remaining set of vertices until the last ear is found. It is the simplest method of all. However, it runs in O(n^2) time. There are 
many other triangulation algorithms much time efficient than this one.

### Libraries and SDKs

<pre>
1. Win32 SDK (Windowing and event handling) //GlUT/GLFW can be used instead
2. Glew (OpenGL wrangler Library)
3. Glm (OpenGl assisting Lib)
</pre>

### Implementation

##### 1. DLL.h - DLL.cpp

DLL stands for Doubly-Linked-List. It contains functionalities to insert/delete elements in a circular Doubly Linked List. It is used to hold the
vertices of the polygon.

##### 2. EarClippingMethod.h - EarClippingMethod.cpp

It contains functionalities associated with polygon triangulation.

##### 3. Triangle.h - Triangle.cpp

It hold the triangles created in the triangulation method.

### Algorithm

<pre>
1. point temp to dll->head 
2. loop until dll->vertices.size > 2 
3.   if(vertex is not reflex) 
4.     if(any other vertex is not inside triangle formed by (temp->prev, temp, temp->next))
5.       triangles.push(temp->prev, temp, temp->next) //Create Triangle 
5.       dll->remove(temp) //Remove Ear 
7.   temp = temp->next 
</pre>

### Reflex Vertex

A reflex vertex of a polygon has interior angle greater than 180. 

##### How to find reflex angle ?

<pre>
While traversing a polygon in counter-clockwise direction, the vertex at which a right turn is taken is identified as a reflex vertex.
Computational Steps:
For vertices v1, v2, v3 - v3 is a reflex vertex:
1. If determinant(v2 - v1, v3 - v2) > 0 ---> Reflex Vertex.
2. Else it is a Convex Vertex.
</pre>

### Inside Triangle Test

<pre>
For an ear to exist, the triangle formed by it's vertices should not contain any other vertices of the polygon.
Computing Point-Inside-Triangle:
1. Compute Barycentric Coordinates u, v
2. Check for condition (u >= 0 && v >= 0 && u+v > 1)
3. If true, the point is inside else outside.
</pre>

### Results

![Result 1](https://github.com/purvakulkarni15/Polygon-Triangulation/blob/master/Result2.PNG)

![Result 2](https://github.com/purvakulkarni15/Polygon-Triangulation/blob/master/Result1_EarClipping.PNG)
