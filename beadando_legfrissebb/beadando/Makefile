all:
	gcc -Iinclude/ src/app.c src/draw.c src/model.c src/verda.c src/kocsi.c src/car.c src/forgo.c src/camera.c src/main.c src/scene.c src/texture.c src/utils.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lobj -lopengl32 -lm -o cube.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/app.c src/draw.c src/model.c src/verda.c src/kocsi.c src/car.c src/forgo.c src/camera.c src/main.c src/scene.c src/texture.c src/utils.c -lobj -lSDL2 -lSDL2_image -lGL -lm -o cube -Wall -Wextra -Wpedantic
