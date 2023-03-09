cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tanks)

# add the executable
add_executable(Tanks main.cpp base.h
	Animation.h Animation.cpp
	entity.h entity.cpp
	bot.h bot.cpp
	player.h player.cpp
	cell.h cell.cpp
	map.h map.cpp
	projectile.h projectile.cpp
	)

target_link_libraries(Tanks PRIVATE sfml-graphics sfml-system sfml-window)
