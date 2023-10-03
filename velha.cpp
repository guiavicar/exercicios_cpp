/**
 * \file  velha.cpp
 */

#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */

int VerificaVelha( int velha[3][3] )
{	
	/*-------Contador-------*/
	int X;
	int O;
	int vazio;
	for (int i=0 ; i<3 ; i++){
		for (int j=0 ; j<3 ; j++){ /*conta a quantidade de casas vazias*/
			if (velha[i][j] == 0){
				vazio = vazio+1;
			}
			if (velha[i][j] == 1){ /*conta a quantidade de casas com um X*/
				X=X+1;
			}
			if (velha[i][j] == 2){ /*conta a quantidade de casas com um O*/
				O=O+1;
			}
		}
	}


	/*-------horizontal-------*/
	for (int i=0 ; i<3 ; i++){

		if (velha[i][0] == velha[i][1] && velha[i][0] == velha[i][2] && velha[i][0]!=0) /*criterios que identificam uma combinacao horizontal excluindo uma combinacao nula*/
		{  /* verificando se existe uma combinaçao na horizontal*/
			
			return (velha[i][1]); 	/*retorna o tipo da combinacao vencedora*/
		}
	} 
	/*-------vertical--------*/
	for (int j=0 ; j<3 ; j++){

		if (velha[0][j] == velha[1][j] && velha[0][j] == velha[2][j] && velha[0][j]!=0) /*criterios que identificam uma combinacao vertical excluindo uma combinacao nula*/
		{ /* verificando se existe uma combinaçao na vertical*/

			return(velha[1][j]); /*retorna o tipo da combinacao vencedora */
		}
	}
	/*-------diagonal---------*/
	if ((velha[0][0] == velha[1][1] && velha[0][0] == velha[2][2] && velha[0][0]!=0) || (velha[0][2] == velha[1][1] && velha[0][2] == velha[2][0] && velha[0][2]!=0))
	{
			return(velha[1][1]);
	}
	/*-----empate--------*/
	else{
		return(0);
	}

}

