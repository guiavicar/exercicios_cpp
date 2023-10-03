
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
  


TEST_CASE( "Testa velha", "[single-file]" ) {
	SECTION("testa horizontal"){
		int teste_combinacao_horizontal[3][3]= { 
		 				  { 0, 0, 0 }, 
	                      { 2, 2, 2 },
						  { 0, 0, 0 }
					  };
    	REQUIRE( VerificaVelha(teste_combinacao_horizontal) == 2 );
	};

	SECTION("Testa vertical", "[single-file]"){
		int teste_combinacao_vertical[3][3]={
						  {1, 0, 0},
						  {1, 0, 0},
						  {1, 0, 0}
					  };
		REQUIRE( VerificaVelha(teste_combinacao_vertical) == 1 );
	};
	SECTION("testa diagonal"){
		int teste_combinacao_diagonal[3][3] = {
						   {1, 0, 0},
						   {0, 1, 0},
						   {0, 0, 1}

					   };
		REQUIRE( VerificaVelha(teste_combinacao_diagonal) == 1 );
	};
	SECTION("testa empate"){
		int teste_empate[3][3] = {
						   {1, 2, 1},
						   {1, 2, 2},
						   {2, 1, 1}

					   };
		REQUIRE( VerificaVelha(teste_empate) == 0 );
	};
}
 
