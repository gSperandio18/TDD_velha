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
 * \file velha.cpp
 */
#include "velha.hpp"

/**
 * @brief verifica situacao do jogo da velha
 * @author Programador
 * @param  velha descreve o parametro
 *
 *  Descrever o que a funcao faz
 */

int VerificaPlayerVencedor(int velha[3][3]) {
  int vencedorX = 0;
  int vencedorO = 0;

  for (int i = 0; i < 3; i++) {
    int pontosX = 0;
    int pontosO = 0;

    // verifica linha
    for (int j = 0; j < 3; j++) {
      if (velha[i][j] == 1) {
        pontosX++;
      } else if (velha[i][j] == 2) {
        pontosO++;
      }

      if (pontosX == 3) {
        vencedorX = 1;
      } else if (pontosO == 3) {
        vencedorO = 1;
      }
    }
  }

  // verifica coluna
  for (int j = 0; j < 3; j++) {
    int pontosX = 0;
    int pontosO = 0;

    for (int i = 0; i < 3; i++) {
      if (velha[i][j] == 1) {
        pontosX++;
      } else if (velha[i][j] == 2) {
        pontosO++;
      }

      if (pontosX == 3) {
        vencedorX = 1;
      } else if (pontosO == 3) {
        vencedorO = 1;
      }
    }
  }

  // verifica diagonal principal
  for (int i = 0; i < 3; i++) {
    int pontosX = 0;
    int pontosO = 0;

    for (int j = 0; j < 3; j++) {
      if (i == j) {
        if (velha[i][j] == 1) {
          pontosX++;
        } else if (velha[i][j] == 2) {
          pontosO++;
        }

        if (pontosX == 3) {
          vencedorX = 1;
        } else if (pontosO == 3) {
          vencedorO = 1;
        }
      }
    }
  }

  // verifica diagonal inversa
  for (int i = 0; i < 3; i++) {
    int pontosX = 0;
    int pontosO = 0;

    for (int j = 0; j < 3; j++) {
      if (i + j == 2) {
        if (velha[i][j] == 1) {
          pontosX++;
        } else if (velha[i][j] == 2) {
          pontosO++;
        }

        if (pontosX == 3) {
          vencedorX = 1;
        } else if (pontosO == 3) {
          vencedorO = 1;
        }
      }
    }
  }

  if (vencedorO == 1 && vencedorX == 1) {
    return -2;
  }

  if (vencedorO == 0 && vencedorX == 0) {
    return 0;
  }

  if (vencedorX == 1) {
    return 1;
  }

  if (vencedorO == 1) {
    return 2;
  }

  return -1;  // se não for nenhuma das condições, está indefinido
}

int VerificaVelha(int velha[3][3]) {
  // verificar X vencedor
  return VerificaPlayerVencedor(velha);
}
