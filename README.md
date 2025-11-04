# bismuth
Offers general purpose classes/utilities I made for using in my [D++](https://dpp.dev/) bots.

# Features
- General classes
    - `logger` - a logger, that can be attached with `dpp:cluster::on_log`. See `log` below for configuration
- Utilities
    - `log` - log functions, that use [Aurora](https://github.com/Fryy55/aurora) as a base. Functions log to the configured console stream and added targets (use `aurora::*` classes/utils to configure). **Refer to Aurora's safety precautions regarding `aurora::TargetManager::logToDir` when using it!**
    - Macros
        - `check-for-channels.hpp` - normal/coro macros for returning from a `void`/`dpp::task<void>` returning function when the channel in an event doesn't match the specified one
        - `options.hpp` - normal/coro macros for working with command options and subcommands. Check the header for more info on specific macros
        - `requests.hpp` - normal/coro macros for verifying requests. Also allows to assign numeric tags to request for easier understanding of what exactly failed

# Usage
## Installing
Add the following lines to your `CMakeLists.txt`:

```cmake
CPMAddPackage("gh:Fryy55/bismuth@1.0.0")
target_link_libraries(${PROJECT_NAME} bismuth)
```
Replace `1.0.0` with the version you want to use.

You can also use a specific tag/branch/commit of bismuth like this:

`CPMAddPackage("gh:Fryy55/bismuth#b492c63")` - tag/branch/commit hash

## Using
Simply include headers (e.g. `#include <bismuth/classes/logger.hpp>`) and use them in your mods!

There is also a general "include everything" header (`<bismuth/bismuth.hpp>`), as well as grouped headers (e.g. `<bismuth/utils/utils.hpp>`).

> [!TIP]
> Normally, every class is located in the `bismuth::*` namespace, however, if you are fine with leaking bismuth to every TU, you can add `set(BISMUTH_USE_NAMESPACE TRUE)` to your `CMakeLists.txt`. This will precompile the header that solely uses the namespace, thus enabling you to use features directly without explicitly using the namespace everywhere.

# License
This project is distributed under the **GNU Affero General Public License v3.0 (GNU AGPLv3)**.

See `LICENSE` for permissions, conditions and limitations.
