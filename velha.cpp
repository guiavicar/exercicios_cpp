/**
 * \file  velha.cpp
 */

#include <iostream>
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
	for (int i=0 ; i<3 ; i++){

		if (velha[i][0] == velha[i][1] && velha[i][0] == velha[i][2] && velha[i][0]!=0)
		{  /* verificando se existe uma combinaçao na horizontal*/
			
			return (velha[i][1]); 	/*retorna o tipo da combinacao vencedora*/
		}
	} 
	
	for (int j=0 ; j<3 ; j++){

		if (velha[0][j] == velha[1][j] && velha[0][j] == velha[2][j] && velha[0][j]!=0)
		{ /* verificando se existe uma combinaçao na vertical*/

			return(velha[1][j]); /*retorna o tipo da combinacao vencedora */
		}

	}
}

