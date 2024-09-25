import turtle

# Crear una pantalla para dibujar
screen = turtle.Screen()
screen.bgcolor("white")  # Fondo blanco

# Crear una tortuga para dibujar
flor = turtle.Turtle()
flor.shape("turtle")
flor.speed(10)  # Velocidad rápida para dibujar

# Función para dibujar un pétalo
def dibujar_petalo():
    for _ in range(2):
        flor.circle(100, 60)  # Dibujar un arco
        flor.left(120)

# Dibujar la flor con 6 pétalos
for _ in range(6):
    dibujar_petalo()
    flor.right(60)

# Dibujar el tallo
flor.right(90)
flor.forward(300)

# Cerrar la ventana al hacer clic
screen.exitonclick()
