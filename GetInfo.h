#pragma once
/// <summary>
/// 色々な数値
/// </summary>
class GetInfo
{
public:
	/// <summary>
	/// マップチップのでかさ
	/// </summary>
	/// <returns></returns>
	static int GetBlockSize() { return blockSize_; }
	/// <summary>
	/// マップの高さ
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