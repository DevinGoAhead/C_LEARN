#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 5
#define COL 5

void InitializationBoard(char arr[][COL], int row, int col);
void DisplayBoard(char arr[][COL], int row, int col);
void PlayerMove(char arr[][COL], int row, int col);
char isWin(char arr[][COL], int row, int col);
void ComputerMove(char arr[][COL], int row, int col);
