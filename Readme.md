## Graphics Pipeline

* Vertex shader - lze vložit vlastní shadery
    * prý transformuje 3d pozice na jiné 3d pozice
* Geoemtry shader - lze vložit vlastní shadery
    * bere vrcholy nějakého primitiva a může vygenerovat další vrcholy/primitiva
* Shape(primitive) assembly
    * získane vrcholy pro primitiva a sestaví primitiva
* Rasterization
    * namapuje primitiva na pixely obrazovku, tzv. fragmenty
* Fragment shader - lze vložit vlastní shadery
    * před tím než běží fragment shader, je proveden  *cliping*, který odstraní fragmenty mimo naš pohled
    * vypočítá konečnou barvu pixelu
* Tests and blending
    * alpha test a blending
    * kontroluje hloubku a šablonu(stencil) hodnotu a zjistí jestli fragmenty je za, nebo před jiným objektem jestli se má vykreslovat
    * potom se zkontroluje alpha hodnotu(průsvitnost) a zobrazí objekt podle toho

## Důležité pojmy

* NDC - normalized device coordinates

## Důležité zdroje informací

* https://learnopengl.com/Getting-started/Hello-Triangle
* https://cent.felk.cvut.cz/courses/PGR/lectures/02_ShadersProgram.pdf
* https://thebookofshaders.com/
* builtin_glsl variables https://www.khronos.org/opengl/wiki/Built-in_Variable_(GLSL)
* opengl-wiki -> skvělý zdroj informací https://www.khronos.org/opengl/wiki/Uniform_(GLSL)