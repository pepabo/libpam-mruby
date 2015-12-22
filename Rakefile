MRUBY_CONFIG=File.expand_path(ENV['MRUBY_CONFIG'] || 'build_config.rb')

file :mruby do
  sh 'git clone --depth=1 git://github.com/mruby/mruby.git'
end

desc 'build_mruby'
task :build_mruby => :mruby do
  sh "cd mruby && MRUBY_CONFIG=#{MRUBY_CONFIG} rake all"
end

desc 'mruby.c'
task :build_mruby_c => :build_mruby do
  sh 'gcc -Imruby/include -iquote./src -fPIC -fno-stack-protector -o build/mruby.o -c src/mruby.c'
end

desc 'pam.c'
task :build_pam_c => :build_mruby_c do
  sh 'gcc -Imruby/include -iquote./src -fPIC -fno-stack-protector -o build/pam.o -c src/pam.c'
end

desc 'build'
task :build => [:build_mruby_c, :build_pam_c] do
  sh 'ld -x --shared -o build/mruby.so build/mruby.o build/pam.o'
end

desc 'install'
task :install => 'build/mruby.so' do
  sh "install build/mruby.so /usr/lib64/security/pam_mruby.so"
end

desc 'test'
task :test => :build do
end

desc 'clean'
task :clean do
  sh "rm -rf mruby/ build/*.*"
end

task :default => :test
