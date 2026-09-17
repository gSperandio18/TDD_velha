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

bool VerificaPlayerVencedor(int velha[3][3], int player) {
  // checar linhas e colunas
  for (int i = 0; i < 3; i++) {
    if (velha[i][0] == player && velha[i][1] == player &&
        velha[i][2] == player) {
      return true;
    }
    if (velha[0][i] == player && velha[1][i] == player &&
        velha[2][i] == player) {
      return true;
    }
  }

  // checar diagonal principal
  if (velha[0][0] == player && velha[1][1] == player && velha[2][2] == player) {
    return true;
  }

  return false;
}

int VerificaVelha(int velha[3][3]) {
  // realizar contagem de células
  int numX = 0;
  int numO = 0;
  int numVazio = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (velha[i][j] == 0) numVazio++;
      if (velha[i][j] == 1) numX++;
      if (velha[i][j] == 2) numO++;
    }
  }

  int diferencaEntreXeO = numX - numO;

  if (diferencaEntreXeO < 0 || diferencaEntreXeO > 1) {
    return -2;  // jogo impossivel
  }

  bool XVenceu = VerificaPlayerVencedor(velha, 1);
  bool OVenceu = VerificaPlayerVencedor(velha, 2);

  if (XVenceu && OVenceu) {
    return -2;  // impossivel
  }

  if (XVenceu) {
    return (diferencaEntreXeO == 1) ? 1 : -2;  // Para X ganhar, numX = numO + 1
  }

  if (OVenceu) {
    return (diferencaEntreXeO == 0) ? 2 : -2;  // Para O ganhar, numX = numO
  }

  if (numX > 5 || numO > 4) {
    return -2;
  }

  if (numVazio == 0) {
    return 0;  // tabuleiro cheio
  }

  return -1;  // jogo indefinido
}
