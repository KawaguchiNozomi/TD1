#pragma once
/// <summary>
/// �F�X�Ȑ��l
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
	static int GetMapWidth() { return mapWidth_; }
	static int GetWindowWidth() { return windowWidth_; }
	static int GetWindowHeight() { return windowHeight_; }
	static int GetPlayerSpriteSize() { return playerSpriteSize_; }
	static int GetPlayerSpriteRadius() { return playerSpriteRadius_; }

private:
	static const int blockSize_ = 64;
	static const int playerSpriteSize_ = 64;
	static const int playerSpriteRadius_ = playerSpriteSize_ / 2;
	static const int mapHeight_ = 11;
	static const int mapWidth_ = 30;
	static const int windowWidth_ = 1000;
	static const int windowHeight_=720;
};