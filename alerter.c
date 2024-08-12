#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius)
{

        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        return 500;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200)
    {
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(97.4);
    alertInCelcius(45.6);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 2); 
    printf("All is well (maybe!)\n");
    return 0;
}
