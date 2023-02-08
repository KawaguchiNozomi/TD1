#pragma once
/// <summary>
/// �F�X�Ȑ��l �傫���Ȃǂ̒萔
/// </summary>
class GetInfo
{
public:
	/// <summary>
	/// �}�b�v�`�b�v�̂ł���
	/// </summary>
	/// <returns></returns>
	static int GetBlockSize() { return blockSize_; }
	/// <summary>
	/// �}�b�v�̍���
	/// </summary>
	/// <returns></returns>
	static int GetMapHeigth() { return mapHeight_; }
	/// <summary>
	/// �}�b�v�̒���
	/// </summary>
	/// <returns></returns>
	static int GetMapWidth() { return mapWidth_; }
	/// <summary>
	/// �E�B���h�E�T�C�Y�̉���
	/// </summary>
	/// <returns></returns>
	static int GetWindowWidth() { return windowWidth_; }
	/// <summary>
	/// �E�B���h�E�T�C�Y�̏c��
	/// </summary>
	/// <returns></returns>
	static int GetWindowHeight() { return windowHeight_; }
	/// <summary>
	/// �v���C���[�̃X�v���C�g�T�C�Y
	/// </summary>
	/// <returns></returns>
	static int GetPlayerSpriteSize() { return playerSpriteSize_; }
	/// <summary>
	/// �v���C���[�̃X�v���C�g���a
	/// </summary>
	/// <returns></returns>
	static int GetPlayerSpriteRadius() { return playerSpriteRadius_; }
	/// <summary>
	/// �������x
	/// </summary>
	/// <returns></returns>
	static int GetBaseLevel() { return baseLevel_; }

private:
	static const int blockSize_ = 64;
	static const int playerSpriteSize_ = 64;
	static const int playerSpriteRadius_ = playerSpriteSize_ / 2;
	static const int mapHeight_ = 11;
	static const int mapWidth_ = 100;
	static const int windowWidth_ = 1000;
	static const int windowHeight_=720;
	static const int baseLevel_ = blockSize_ * 8;
};