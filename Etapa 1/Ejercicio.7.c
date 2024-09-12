#include <stdio.h>

int main() {
    float valor_articulo, impuesto = 0, precio_final;
    
    printf("Ingrese el valor del articulo: ");
    scanf("%f", &valor_articulo);
    
    if (valor_articulo > 5000) {

        // Primeros $200 sin impuesto
        valor_articulo -= 200;
        // Siguientes $200 con 30% de impuesto
        impuesto += 200 * 0.30;
        valor_articulo -= 200;
        // Resto con 50% de impuesto
        impuesto += valor_articulo * 0.50;

    } else if (valor_articulo > 400) {

        // Primeros $200 sin impuesto
        valor_articulo -= 200;
        // Siguientes $200 con 30% de impuesto
        impuesto += 200 * 0.30;
        valor_articulo -= 200;
        // Resto con 40% de impuesto
        impuesto += valor_articulo * 0.40;

    } else if (valor_articulo > 200) {

        // Primeros $200 sin impuesto
        valor_articulo -= 200;
        // Resto con 30% de impuesto
        impuesto += valor_articulo * 0.30;

    }
    else impuesto = 0;
    
    // Precio final es el valor original más el impuesto calculado
    precio_final = valor_articulo + impuesto;
    
    printf("El precio con impuestos es de: %.2f\n", precio_final);
    
    return 0;
}
