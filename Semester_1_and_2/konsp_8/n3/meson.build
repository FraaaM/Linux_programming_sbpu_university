project(
    'myproject',                       # название проекта
    'cpp',                             # язык
    version: '0.1.0',                  
    meson_version: '>=0.50',           
    default_options: ['cpp_std=c++11'] # стандарт C++
)
myproject_src = files([
    'main.cpp' # список исходных файлов
])

zlib = dependency('zlib') # подключаем zlib

executable(
    'myproject',              # название исполняемого файла
    include_directories: [--], # где ищутся заголовочные файлы
    sources: myproject_src,   # список исходный файлов
    dependencies: [zlib],         # зависимости проекта
    install: true       ## устанавливать ли файл    
)
