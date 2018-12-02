#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "DxLib.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	if (__argc == 1)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "exe��pmd/mqo/pmx/mqx/mv1���h���b�O�A���h�h���b�v���Ă��������B\n�����L�[�������Ă��������B");

		WaitKey();

		return -1;
	}


	// ---------------------------------------------------------------------
	int modelHandle = MV1LoadModel(__argv[1]);

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
			saveFile << i << "," << MV1GetTextureColorFilePath(modelHandle, i) << std::endl;
		}
	}

	// �t�@�C�������
	saveFile.close();

	DrawFormatString(0, 0, GetColor(255,255,255), "�t�@�C���ǂݍ��݋y��csv�����o���I�����܂���\n�����L�[�������Ă��������B");

	WaitKey();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}