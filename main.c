#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include <inttypes.h>
#define inputSize 256
#define numberOfWords 8

typedef struct {
	char *dedicator;
	int8_t bancnota1;
	int8_t bancnota2;
	char *barosan;
} tip1;   // baiatu ai gresit buzunaru

typedef struct {
	char *dedicator;
	int16_t bancnota1;
	int32_t bancnota2;
	char *barosan;
} tip2;

typedef struct {
	char *dedicator;
	int32_t bancnota1;
	int32_t bancnota2;
	char *barosan;
} tip3;


int add_last(void **arr, int *len, data_structure *data) {

	void **offset = (*arr) + (*len);
	u_char tip = (u_char)data->header->type;
	if(realloc(*arr, (size_t)((size_t)len + (size_t)data->header->len) ) )
		return 0;

	memcpy(*offset, &tip, sizeof(u_char));
	*offset += sizeof(u_char);
	memcpy(*offset, &tip, sizeof(u_int));
	*offset += sizeof(u_int);
	switch (tip) {
		case 1:
		{
			tip1 *pAux = (tip1*)data->data;
			memcpy(*offset, pAux->dedicator, strlen((char*)pAux->dedicator)+1);
			*offset += strlen((char*)pAux->dedicator)+1;
			memcpy(*offset, &pAux->bancnota1, sizeof(int8_t));
			*offset += sizeof(int8_t);
			memcpy(*offset, &pAux->bancnota2, sizeof(int8_t));
			*offset += sizeof(int8_t);
			memcpy(*offset, pAux->barosan, strlen((char*)pAux->barosan)+1);
			*offset += strlen((char*)pAux->barosan)+1;
			break;
		}
		case 2:
		{
			tip2 *pAux = (tip2*)data->data;
			memcpy(*offset, pAux->dedicator, strlen((char*)pAux->dedicator)+1);
			*offset += strlen((char*)pAux->dedicator)+1;
			memcpy(*offset, &pAux->bancnota1, sizeof(int16_t));
			*offset += sizeof(int16_t);
			memcpy(*offset, &pAux->bancnota2, sizeof(int32_t));
			*offset += sizeof(int32_t);
			memcpy(*offset, pAux->barosan, strlen((char*)pAux->barosan)+1);
			*offset += strlen((char*)pAux->barosan)+1;
			break;
		}
		case 3:
		{
			tip3 *pAux = (tip3*)data->data;
			memcpy(*offset, pAux->dedicator, strlen((char*)pAux->dedicator)+1);
			*offset += strlen((char*)pAux->dedicator)+1;
			memcpy(*offset, &pAux->bancnota1, sizeof(int32_t));
			*offset += sizeof(int32_t);
			memcpy(*offset, &pAux->bancnota2, sizeof(int32_t));
			*offset += sizeof(int32_t);
			memcpy(*offset, pAux->barosan, strlen((char*)pAux->barosan)+1);
			*offset += strlen((char*)pAux->barosan)+1;
			break;
		}
		default:
			return 0;
	}

*len += data->header->len;
if(*len - (int)(*offset - *arr) != 0)
	return 1;
else
	return 0;
}

int add_at(void **arr, int *len, data_structure *data, int index) {

}

void find(void *data_block, int len, int index) {

}

int delete_at(void **arr, int *len, int index) {

}


tip1 *genStruct1(char* sarantoc, int8_t cinciLei, int8_t zeceLei, char* smecheras) {
		tip1 *data = (tip1*)calloc(1, sizeof(tip1));
		data->dedicator = (char*)calloc(1, strlen(sarantoc)+1);
		strcpy(data->dedicator, sarantoc);
		data->bancnota1 = cinciLei;
		data->bancnota2 = zeceLei;
		data->barosan = (char*)calloc(1, strlen(smecheras)+1);
		strcpy(data->barosan, smecheras);
		return data;

}

tip2 *genStruct2(char* lucrezLaLidl, int8_t blaga , int8_t eminescu, char* tanc) {
	tip2 *data = (tip2*)calloc(1, sizeof(tip2));
	data->dedicator = (char*)calloc(1, strlen(lucrezLaLidl)+1);
	strcpy(data->dedicator, lucrezLaLidl);
	data->bancnota1 = blaga;
	data->bancnota2 = eminescu;
	data->barosan = (char*)calloc(1, strlen(tanc)+1);
	strcpy(data->barosan, tanc);
	return data;
}

tip3 *genStruct3(char* boier, int8_t eminescu, int8_t sutadeEuro, char* barosan) {
	tip3 *data = (tip3*)calloc(1, sizeof(tip3));
	data->dedicator = (char*)calloc(1, strlen(boier)+1);
	strcpy(data->dedicator, boier);
	data->bancnota1 = eminescu;
	data->bancnota2 = sutadeEuro;
	data->barosan = (char*)calloc(1, strlen(barosan)+1);
	strcpy(data->barosan, barosan);
	return data;
}

data_structure *genDataStruct (void *info, int type) {

	data_structure *celula = (data_structure*)calloc(1, sizeof(data_structure));
	celula->data = info;
	head *infoHeader = (head*)calloc(1, sizeof(head));
	infoHeader->type = type;

	int infoLen = 0;
	switch (type) {
		case 1 :
		{
			tip1 *pAux = (tip1*)info;
			infoLen = (int)(strlen((char*)pAux->dedicator) + strlen((char*)pAux->barosan)+2);
			infoLen += pAux->bancnota1 + pAux->bancnota2;
			break;
    }
		case 2 :
		{
			tip2 *pAux = (tip2*)info;
			infoLen = (int)(strlen((char*)pAux->dedicator) + strlen((char*)pAux->barosan)+2);
			infoLen += pAux->bancnota1 + pAux->bancnota2;
			break;
		}
		case 3 :
		{
			tip3 *pAux = (tip3*)info;
			infoLen = (int)(strlen((char*)pAux->dedicator) + strlen((char*)pAux->barosan)+2);
			infoLen += pAux->bancnota1 + pAux->bancnota2;
			break;
		}
		default:
			return NULL;

	}

	infoHeader->len = sizeof(data_structure) + sizeof(head) + sizeof(info) + infoLen;
	celula->header = infoHeader;

	return celula;
}

int main() {
	// the vector of bytes u have to work with
	// good luck :)
	void *arr = NULL;
	int len = 0;




while(1) {

// start parsare

char *comanda = (char*)calloc(inputSize, sizeof(char));
char **cuvant = (char**)calloc(numberOfWords, sizeof(char*));
int contorWordVec = 0;
fgets(comanda, inputSize, stdin);
if (strrchr(comanda, '\n')) {
  *strrchr(comanda, '\n') = '\0';
}
cuvant[contorWordVec] = strtok(comanda, " ");
while (cuvant[contorWordVec]) {
contorWordVec++;
cuvant[contorWordVec] = strtok(NULL, " ");
}

// end parsare

// add last  block

if (strcmp(cuvant[0], "insert") == 0) {
	int8_t tip = (int8_t)atoi(cuvant[2]);
	data_structure *element = NULL; // vezi poate ramane dangling pointer daca nu il faci null dupa
	switch (tip) {

		case 1:
		{
			int8_t bancnota1 = (int8_t)atoi(cuvant[3]);
			int8_t bancnota2 = (int8_t)atoi(cuvant[4]);
			tip1 *pAux = genStruct1(cuvant[2], bancnota1, bancnota2, cuvant[5]);
			element = genDataStruct(pAux, tip);
			break;
		}

		case 2:
		{
			int16_t bancnota1 = (int16_t)atoi(cuvant[3]);
			int32_t bancnota2 = (int32_t)atoi(cuvant[4]);
			genStruct2(cuvant[2], bancnota1, bancnota2, cuvant[5]);
			tip2 *pAux = genStruct2(cuvant[2], bancnota1, bancnota2, cuvant[5]);
			element = genDataStruct(pAux, tip);
			break;
		}

		case 3:
		{
			int32_t bancnota1 = (int32_t)atoi(cuvant[3]);
			int32_t bancnota2 = (int32_t)atoi(cuvant[4]);
			genStruct3(cuvant[2], bancnota1, bancnota2, cuvant[5]);
			tip3 *pAux = genStruct3(cuvant[2], bancnota1, bancnota2, cuvant[5]);
			element = genDataStruct(pAux, tip);
			break;
		}
	}

	if(add_last(&arr,&len, element))
		return 1;
}



//  exit block
if (strcmp(cuvant[0], "exit") == 0) {

	// free vector //


	contorWordVec = 0;
	while(cuvant[contorWordVec]) {
		free(cuvant[contorWordVec]);
		contorWordVec++;
	}
	free(cuvant);
	free(comanda);

	return 1;
}


// start dealocare vector de cuvinte din input
contorWordVec = 0;
while(cuvant[contorWordVec]) {
	cuvant[contorWordVec] = NULL;
	contorWordVec++;
}
free(cuvant);
free(comanda);
// end dealocare vector de cuvinte din input
}




	return 0;
}
