
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
  REQUIRE(VerificaVelha(teste3) == 1);  // verifica x vencedor na diagonal principal
}
