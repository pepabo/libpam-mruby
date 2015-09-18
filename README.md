# libpam-mruby

A PAM module to authenticate user with mruby.

## Usage

Add a file that has a line like below into `/etc/.pam.d` (or other location along with your environment):

```
auth required mruby.so rbfile=/path/to/auth.rb
```

Then write a auth handler in mruby like below:

```ruby
def check(username)
  if username == 'kentaro'
    1
  else
    0
  end
end
```

## How to Build

### Using Docker

On Mac OSX or other:

```
$ docker-compose build libpam-mruby
$ docker-compose run libpam-mruby
```

You'll see the artifact at `build/mruby.so`.

### Build Directly

Install prerequisites like below(on CentOS):

```
$ yum -y install gcc bison
$ yum -y pam pam-devel
```

Then execute `rake` command:

```
$ rake
```

Also you'll see the artifact at `build/mruby.so`.

## Author

Kentaro Kuribayashi

## License

MTG
