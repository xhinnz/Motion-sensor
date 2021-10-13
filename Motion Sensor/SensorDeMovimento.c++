#include <dos.h>
#include <iostream.h>
#include <windows.h>

#define DADOS 0x378
#define STATUS 0x379

typedef short _stdcall (*PtrInp) (shoer EndPorta);
typedef void _stdcall (*PtrOut) (short EndPorta, short valor);

int main(void)
{
  HINSTANCE hLib; //Instância para DLL inpout32.dll.
  PtrInp inportb; //Instância para a função Imp32().
  PtrOut outportb; //Instância para a função Out32().

  //Carrega a DLL na memória.
  hLib = LoadLibrary("inpout32.dll");

  if(hLib == NULL) //Verifica se houve erro.
  {
    std::cout << "LoadLibrary Failed.\n";
    getch();
    return -1;
  }

    //Obtém o endereço da função Inp32 contida na DLL.
    inportb = (PtrInp) GetProcAddress(hLib, "Inp32");

    if(inportb == NULL) //Verifica se huove erro.
    {
        cout << "Erro. A função Inp32 não foi encontrada. \n";
        getch ();
        return -1;
    }

    //Obtém o endereço da função Out32 contida na DLL.
    outportb = (PtrOut) GetProcAddrees(hLib, "Out32");

    if(outportb == NULL) //Verifica se houve erro.
    {
       cout << "GetProcAddress for Oup32 Failed. \n";
       getch();
       return -1;
    }

int SEG1 = 0, MIN1 = 0, SEG2 = 0, MIN2 = 0, TEMPO_TOTAL1, TEMPO_TOTAL2;
unsigned char Status;
while (!kbhit())
{
      Status = inportb (STATUS);
      if ((Status) == 0x77
      {

                 ourportb (DADOS,0x01);
                 SEG1++;
                 _sleep(1000);
                 if (SEG1 > 59)
                 {
                     SEG1 = 0;
                     min1++;
                     }
                     system("CLS");
                     cout << "Sensor 1 ATIVO!    " << MIN1 << " : " << SEG1;
                     TEMPO_TOTAL1 = SEG1 + (MIN1 * 60);
                     }
      if ((Status) == 0x67)
      {
                    SEG2 = 0;
                     MIN2++;
                     }
                     system("CLS");
                     cout << "Sensor 2 ATIVO!    " << MIN2 << " : " << SEG2;
                     TEMPO_TOTAL2 = SEG2 + (MIN2 * 60);
                     }
      if ((Status) == 0x67)
      {
                   outportb(DADOS, 0x01);
                   outportb(DADOS, 0x02);
                   SEG1++;
                   SEG2++;
                   _sleep(1000);
                   if (SEG1 > 59)
                   {
                     SEG1 = 0;
                     MIN1++;
                     }
                   if (SEG2 > 59)
                     {
                      SEG2 = 0;
                      MIN2++;
                      }  
                     system("CLS");
                     cout << "Sensor 1 ATIVO!    " << MIN1 << " : " << SEG1 << "\n";
                     TEMPO_TOTAL1 = SEG1 + (MIN1 * 60);
                     cout << "Sensor 2 ATIVO!    " << MIN2 << " : " << SEG2;
                     TEMPO_TOTAL2 = SEG2 + (MIN2 * 60);
                     }
                     }
                     system("CLS");
                     cout << "Tempo total em que o sensor 1 ficou ATIVO: " << TEMPO_TOTAL1 << "s";
                     cout << "\n\n";
                     cout << "Tempo total em que o sensor 2 ficou ATIVO: " << TEMPO_TOTAL2 << "s";
                     system("PAUSE >= nul");
                     FreeLibrary(hLib); // Libera memória alocada pela DLL.
                     return(0);
                     }[/CODEBOX]
