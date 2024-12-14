#include "Archivos_sensor.h"
int main()
{
    printf("Hello world!\n");
    int i;

    t_sensor *vec=malloc(CANT_REGISTRO*sizeof(t_sensor));
    if(!vec)
    {
        return 0;
    }

    t_dato *sensor=malloc(20*sizeof(t_dato));
    if(!sensor)
    {
        return 0;
    }
    t_sensor *inicio=vec;
    cargarSensor(vec,"sensors.txt");
    seleccion(vec,sizeof(t_sensor),13,cmpCod);

    for(i=0;i<13;i++)
    {

        printf("%s|%0.2f|%s|\n",vec->cod,vec->temperatura,vec->estado);
        vec++;
    }

    cargarPromSensores(inicio,sensor,13);
    for(i=0;i<5;i++)
    {
        if(sensor->temperatura==0)
        {
            printf("%s -Sin informacion confiable-\n",sensor->cod);
            sensor++;
        }
        float promedio=sensor->temperatura/(sensor->cantidad);
        printf("%s |%f\n",sensor->cod,promedio);
        sensor++;
    }



    free(vec);
    return 0;
}
