cmake_minimum_required(VERSION 3.10)

# set the project name
project(game)

# add the executable
add_executable(game main.cpp base.h
	Animation.h Animation.cpp
	entity.h entity.cpp
	bot.h bot.cpp
	player.h player.cpp
	cell.h cell.cpp
	map.h map.cpp
	projectile.h projectile.cpp
	res/res.png
)

target_link_libraries(game PRIVATE sfml-graphics sfml-system sfml-window)

set(RESOURCE_FILES res/res.png)


set_target_properties(game PROPERTIES
	RESOURCE "${RESOURCE_FILES}")
