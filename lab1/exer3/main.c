#include <stdio.h>
#include <stdlib.h>

//zwraca d�. stringa wraz ze spacjami wewn�trz
int length(char str[]){
    int LEN = 0;
    int i = 0;
    while(str[i] != '\0'){
        LEN++;
        i++;
    }
    return LEN - 1;
}

int main()
{
    FILE *file;
    char buffor[4000];  //linia w pliku wejsciowym
    char word[500];     //szukane s�owo
    int line = 1;

    fgets(word, sizeof(word), stdin);
    int len = length(word);

    file = fopen("../test.txt", "r");

    while(fgets(buffor, sizeof(buffor), file) != NULL){

        //odkomentowa� �eby zobaczy� linie pliku wej�ciowego
        //printf("%s", buffor);

        int i = 0;
        int j = 0;

        while(buffor[i] != '\0'){
            //je�li litery si� zgadzaj�
            if(buffor[i] == word[j]){
                while(buffor[i] == word[j] && buffor[i] != '\0'){
                    i++;
                    j++;
                }
                //je�li w linii jest szukane s�owo
                if(j = length(word) && (buffor[i] == ' ' || buffor[i] == '\0')){
                    printf("Wystapienie w linii %d\n", line);
                    break;
                }

            }
            else{
                while(buffor[i] != ' ') {
                    i++;
                    if(buffor[i] == '\0')
                        break;
                 }
            }
            i++;
            j = 0;
        }

        line++;
    }

    fclose(file);
    return 0;
}
