#include "Map.h"

Map::Map(RenderWindow& w, SpriteCreator s) : window(w), spr(s){
}

bool Map::solid(int i, int j) {
	if (TileMap[i][j] == '0'){
		return true;
	}
	return false;
}
void Map::DrawMap() {
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[i][j] == ' ') {
				spr.backgr.setPosition(j * 32, i * 32);
				window.draw(spr.backgr);
			}
			if (TileMap[i][j] == '0') {
				spr.spr_map.setTextureRect(IntRect(64, 0, 32, 32));
				spr.spr_map.setPosition(j * 32, i * 32);
				window.draw(spr.spr_map);
				;
			}
			if (TileMap[i][j] == '1') {
				spr.spr_coins.setPosition(j * 32, i * 32);
				window.draw(spr.spr_coins);
				;
			}
			if (TileMap[i][j] == 'b') {
				spr.spr_cherry.setPosition(j * 32, i * 32);
				window.draw(spr.spr_cherry);
				;
			}
			if (TileMap[i][j] == 'd') {
				spr.spr_diamond.setPosition(j * 32, i * 32);
				window.draw(spr.spr_diamond);
				;
			}
		}
		
}
