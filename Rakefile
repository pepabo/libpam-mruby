file :mruby do
  sh 'git clone --depth=1 git://github.com/mruby/mruby.git'
end

desc 'build'
task :build => :mruby do
  sh 'cd mruby && rake all && cd ../ && gcc -o build/mruby.o -c src/mruby.c -Imruby/include && ld -x --shared -o build/mruby.so build/mruby.o'
end

desc 'test'
task :test => :build do
end

task :default => :test
