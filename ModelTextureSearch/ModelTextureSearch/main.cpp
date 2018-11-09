#include "DxLib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


int main()
{
	// ---------------------------------------------------------------------
	// �c�w���C�u�����̏�����
	if (DxLib_Init() < 0)
	{
		// �G���[�����������璼���ɏI��
		return -1;
	}

	ChangeWindowMode(true);


	// ---------------------------------------------------------------------
	int modelHandle = MV1LoadModel("media\\CLPH_\\CLPH.mv1");

	const int textureNum = MV1GetTextureNum(modelHandle);


	// ---------------------------------------------------------------------
	std::ofstream saveFile;
	saveFile.open("Save.csv");		// �t�@�C���I�[�v��

	// �t�@�C���ǂݍ��ݎ��s
	if (saveFile.fail()) 
	{
		printf("SaveError\n");
	}
	else 
	{
		// �ǂݍ��ݐ���
		saveFile << "ID" << "," << "���O" << "\n";
		for (int i = 0; i < textureNum; i++) 
		{
			saveFile << i << "," << MV1GetTextureColorFilePath(modelHandle, i) << "\n";
		}
	}

	// �t�@�C�������
	saveFile.close();


	// ---------------------------------------------------------------------
	// int MV1SetTextureColorFilePath( int MHandle, int TexIndex, const TCHAR *FilePath ) ;// �J���[�e�N�X�`���̃t�@�C���p�X��ύX����
	// ����g���ĕύX����΂���

	return 0;
}