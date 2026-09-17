
/**
 * MIT No Attribution
 *
 * Copyright (c) 2026 gSperandio.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * \file testa_velha.cpp
 */

#include "velha.hpp"
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_NO_POSIX_SIGNALS  // necessario pois meu fedora usa glibc,
                                       // o gcc buga e o teste fica feio sem
                                       // isso
#include "catch.hpp"

TEST_CASE("Testa velha", "[single-file]") {
  int teste1[3][3] = {{2, 0, 1}, {2, 0, 1}, {0, 0, 1}};
  REQUIRE(VerificaVelha(teste1) == 1);  // verifica X vencedor na coluna

  int teste2[3][3] = {{1, 1, 1}, {2, 0, 0}, {0, 2, 0}};
  REQUIRE(VerificaVelha(teste2) == 1);  // verifica X vencedor na linha

  int teste3[3][3] = {{1, 0, 0}, {2, 1, 0}, {0, 2, 1}};
  REQUIRE(VerificaVelha(teste3) ==
          1);  // verifica x vencedor na diagonal principal

  int teste4[3][3] = {{0, 2, 1}, {2, 1, 0}, {1, 0, 0}};
  REQUIRE(VerificaVelha(teste4) ==
          1);  // verifica x vencedor na diagonal secundária

  // os mesmos 4 testes para vencedor O:

  int teste5[3][3] = {{1, 2, 1}, {1, 2, 0}, {0, 2, 0}};
  REQUIRE(VerificaVelha(teste5) == 2);  // verifica O vencedor na coluna

  int teste6[3][3] = {{1, 1, 0}, {2, 2, 2}, {0, 0, 1}};
  REQUIRE(VerificaVelha(teste6) == 2);  // verifica O vencedor na linha

  int teste7[3][3] = {{2, 0, 0}, {1, 2, 0}, {1, 1, 2}};
  REQUIRE(VerificaVelha(teste7) ==
          2);  // verifica O vencedor na diagonal principal

  int teste8[3][3] = {{0, 1, 2}, {1, 2, 1}, {2, 0, 0}};
  REQUIRE(VerificaVelha(teste8) ==
          2);  // verifica O vencedor na diagonal secundária

  // testes de impossibilidade
  int teste9[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  REQUIRE(VerificaVelha(teste9) == -2);  // verifica impossibilidade de apenas X

  int teste10[3][3] = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
  REQUIRE(VerificaVelha(teste10) == -2);  // verifica impossibilidade de apenas
                                          // O

  int teste11[3][3] = {{1, 0, 1}, {1, 0, 1}, {0, 2, 2}};
  REQUIRE(VerificaVelha(teste11) ==
          -2);  // verifica impossibilidade de pular a vez do X

  int teste12[3][3] = {{1, 1, 1}, {2, 2, 2}, {0, 0, 0}};
  REQUIRE(VerificaVelha(teste12) ==
          -2);  // verifica impossibilidade de haver 2 vencedores

  int teste13[3][3] = {{1, 1, 1}, {1, 1, 2}, {0, 0, 0}};
  REQUIRE(VerificaVelha(teste13) ==
          -2);  // verifica impossibilidade do O jogar mais que 4 vezes

  int teste14[3][3] = {{2, 2, 2}, {2, 2, 2}, {1, 0, 1}};
  REQUIRE(VerificaVelha(teste14) ==
          -2);  // verifica impossibilidade do X jogar mais que 5 vezes

  // teste de empate
  int teste15[3][3] = {{1, 2, 2}, {2, 1, 1}, {1, 1, 2}};
  REQUIRE(VerificaVelha(teste15) == 0);

  // testes de indefinido/inacabado
  int teste16[3][3] = {{0, 2, 0}, {0, 1, 1}, {0, 0, 0}};
  REQUIRE(VerificaVelha(teste16) == -1);

  int teste17[3][3] = {{0, 1, 0}, {2, 0, 0}, {1, 0, 0}};
  REQUIRE(VerificaVelha(teste17) == -1);

  int teste18[3][3] = {{0, 0, 0}, {1, 2, 0}, {0, 0, 0}};
  REQUIRE(VerificaVelha(teste18) == -1);
}
