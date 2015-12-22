MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'default'

  conf.cc do |cc|
    cc.flags << '-fPIC'
  end
end
