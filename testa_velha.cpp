
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*nesse programa todas as situacoes se encaixam em algum criterio. Logo, nenhum teste falha de forma proposital*/

TEST_CASE("Testa velha", "[single-file]"){
	SECTION("testa horizontal"){
		int teste_combinacao_horizontal[3][3]= {/* esse teste representa a situacao perfeita para verificar se a analize horizontal esta correta*/
		 				  { 1, 0, 1 },
	                      { 2, 2, 2 },
						  { 0, 1, 0 }
					  };
    	REQUIRE(VerificaVelha(teste_combinacao_horizontal) == 2 );/*nessa situacao quem ganha o jogo é o "O" e tem como codigo o 2*/
	};

	SECTION("Testa vertical", "[single-file]"){
		int teste_combinacao_vertical[3][3]={/* esse teste representa a situacao perfeita para verificar se a analize vertical esta correta*/
						  {1, 0, 2},
						  {1, 2, 0},
						  {1, 0, 2}
					  };
		REQUIRE(VerificaVelha(teste_combinacao_vertical) == 1 ); /*nessa situacao quem ganha o jogo é o "X" e tem como codigo o 1*/
	};
	SECTION("testa diagonal"){
		int teste_combinacao_diagonal[3][3] = { /*essa situacao representa uma vitoria na diagonal pelo X*/
						   {1, 2, 2},
						   {0, 1, 0},
						   {2, 0, 1}
					   };
		REQUIRE(VerificaVelha(teste_combinacao_diagonal) == 1 );/*o ganhador foi o "X" e tem como codigo o 1*/
	};
	SECTION("testa empate"){
		int teste_empate[3][3] = { /*essa situacao representa o "velha" ou empate*/
						   {1, 2, 2},
						   {2, 1, 1},
						   {1, 1, 2}
					   };
		REQUIRE(VerificaVelha(teste_empate) == 0 ); /*a situacao de empate tem o codigo 0*/
	};
	SECTION("testa impossivel"){
		int teste_impossivel[3][3] = { /*essa é uma situacao impossivel de acontecer no jogo (6 "O" posicionadas contra 3 "X")*/
						   {1, 2, 1},
						   {1, 2, 2},
						   {2, 2, 2}
		};
		REQUIRE (VerificaVelha(teste_impossivel) == -2); /*o resultado impossivel tem como codigo o -2*/
	}
	SECTION("testa indefinido"){
		int teste_indefinido[3][3] = { /*essa situacao representa um jogo que ainda nao se definiu e provavelmente tem mais rodadas a se jogar*/
						   {2, 1, 1},
						   {2, 2, 0},
						   {1, 0, 0}
		};
		REQUIRE (VerificaVelha(teste_indefinido) == -1); /*o codigo pra partida indefinida é -1*/
	}
}