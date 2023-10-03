/**
 * \file  velha.cpp
 */

#include "velha.hpp"


/** 
 * @brief verifica situacao do jogo da velha  
 * @author Guilherme de Avila
 * @param  velha uma matriz 3 por 3
 */

int VerificaVelha( int velha[3][3] ) /*funcao principal que verica a situacao de uma partida de jogo da velha*/
{	
	/*-------Contador-------*/
	int X = 0;
	int O = 0;
	int vazio = 0;
	int variacao; /*variacao entre a quantidade de X e de O*/
	for (int i=0 ; i<3 ; i++) { 
		for (int j=0 ; j<3 ; j++){ /*conta a quantidade de casas vazias*/
			if (velha[i][j] == 0){
				vazio = vazio + 1;
			}
			if (velha[i][j] == 1){ /*conta a quantidade de casas com um X*/
				X= X + 1;
			}
			if (velha[i][j] == 2){ /*conta a quantidade de casas com um O*/
				O= O + 1;
			}
		}
	}
	/*transforma um possivel numero negativo em positivo*/
	variacao = X-O;
	if (variacao < 0) {
		variacao = variacao * -1;
	}
	/*------impossivel------*/

	if (variacao >= 2) { /*este e o primeiro caso. se em qualquer hipotese houver mais que dois marcadores (X ou O) ja é configurado como impossivel*/
		return (-2);
	}

	/*-------horizontal-------*/
	for (int i=0 ; i<3 ; i++) {

		if (velha[i][0] == velha[i][1] && velha[i][0] == velha[i][2] && velha[i][0]!=0) /*criterios que identificam uma combinacao horizontal excluindo uma combinacao nula*/
		{  /* verificando se existe uma combinaçao na horizontal*/
			return (velha[i][1]); 	/*retorna o tipo da combinacao vencedora*/
		}
	} 
	/*-------vertical--------*/
	for (int j=0 ; j<3 ; j++) {

		if (velha[0][j] == velha[1][j] && velha[0][j] == velha[2][j] && velha[0][j]!=0) /*criterios que identificam uma combinacao vertical excluindo uma combinacao nula*/
		{ /* verificando se existe uma combinaçao na vertical*/
			return(velha[1][j]); /*retorna o tipo da combinacao vencedora */
		}
	}
	/*-------diagonal---------*/
	if ((velha[0][0] == velha[1][1] && velha[0][0] == velha[2][2] && velha[0][0]!=0) || (velha[0][2] == velha[1][1] && velha[0][2] == velha[2][0] && velha[0][2]!=0)) /*criterios que identificam uma cominacao diagonal que exclui uma combinacao nula*/
	{
			return(velha[1][1]);
	}
	/*-----indefinido--------*/
	if (vazio>0) {
		return(-1); /*com a ajuda das definicoes anteriores, agora em qualquer situaçao que aparecer um espaco vazio ja se configura como indefinido*/
	}				/*exemplo: existindo uma matriz que falta ainda um espaco, que ainda nao tem um ganhador e nao é uma partida impossivel, significa que alguem ainda precisa jogar, logo indeterminado*/

 
	/*-----empate--------*/
	else {
		return(0); /*nesse ultimo caso toda e qualquer situacao que nao foi filtrada nas situacoes anteriores se configurará em um empate ou "velha"*/
	}
}