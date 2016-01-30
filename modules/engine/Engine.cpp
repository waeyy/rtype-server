//
// Game.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/modules/engine
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Jan  3 13:31:45 2016 SOIDIKI Djamil
// Last update Sun Jan  3 14:23:53 2016 SOIDIKI Djamil
//

#ifndef		_GAME_HH_
# define	_GAME_HH_

#include	<iostream>
#include	<vector>

namespace	Engine {

  class		Game {
    
  private:
    std::vector<IMonster*>	_monsters;

  public:
    Game();
    ~Game();
    
    void	fill();
    void	update();
    void	render();
  };
}

#endif		/* _GAME_HH_ */
