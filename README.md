# libpam-mruby

A PAM module to authenticate user with mruby.

## Usage

Add a file that has a line like below into `/etc/.pam.d` (or other location along with your environment):

```
auth sufficient pam_mruby.so rbfile=/path/to/auth.rb try_first_pass
```

Then write an auth handler in mruby like below.

`auth.rb`:

```ruby
def authenticate(username, password)
  if username == 'kentaro' && password == 'p@ssw0rd'
    true
  else
    false
  end
end
```

`authenticate()` method at top-level is called when your mruby handler is executed.

For more practical usage, you can use this module, for instance, to handle authentication request using some external user information repository service.

## How to Build

### Using Docker

On Mac OSX or other:

```
$ docker-compose build libpam-mruby
$ docker-compose run libpam-mruby
```

You'll see the artifact at `build/pam_mruby.so`.

### Build Directly

Install prerequisites like below(on CentOS):

```
$ yum -y install gcc bison rake
$ yum -y pam pam-devel
```

Then execute `rake` command:

```
$ rake
```

Also you'll see the artifact at `build/pam_mruby.so`.

## Author

* Kentaro Kuribayashi
* Uchio KONDO

## License

MIT
