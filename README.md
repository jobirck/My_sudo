# my_sudo

## Description
`my_sudo` is a re-implementation of the `sudo` command in C language.  
This program allows users to execute commands with another user's privileges while following the rules defined in the `/etc/sudoers` file.

## Compilation
The project is compiled using a `Makefile` that includes the following rules:
- `make`: compiles the project
- `make clean`: removes object files
- `make fclean`: removes object files and the executable
- `make re`: fully recompiles the project

## Usage
```sh
./my_sudo -h
```
Displays the program help.

```sh
./my_sudo [-ugEs] [command [arguments ...]]
```
Executes a command with another user's privileges.

### Examples
```sh
./my_sudo whoami
```
Displays `root` if authentication is successful.

```sh
./my_sudo -u toto whoami
```
Executes `whoami` as user `toto`.

## Features
- Reads security rules from `/etc/sudoers`
- Authenticates users with their password (without using PAM)
- Manages errors and login attempts (max 3 tries)
- Respects permissions and restrictions defined in the `sudoers` file
- Supports User Aliases in the `sudoers` file

## Constraints
- Only standard libC functions are allowed, except:
  - `getpw*`, `*getsp*`, `getgr*`
  - `fork*`, `clone*`, `openat*`
- Error messages must be displayed on `stderr`, and the program must exit with code `84` in case of an error.

## Security
Since this project is an alternative to `sudo`, it must be secure:
- No information leaks when entering the password
- Strict validation of user inputs
- Restricted access to commands based on `/etc/sudoers`

## Warning
⚠️ **Modifying the `/etc/sudoers` file**  
Be careful when modifying this file, as an error could render your system unusable. Test with dedicated user accounts before applying it to a real environment.


