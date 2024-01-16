Passing all tests as of 1.16.2024

Will add echo test next

```
[==========] Running 4 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 1 test from NetworkFactoryTest
[ RUN      ] NetworkFactoryTest.FactoryConstructionTest
[       OK ] NetworkFactoryTest.FactoryConstructionTest (0 ms)
[----------] 1 test from NetworkFactoryTest (0 ms total)

[----------] 2 tests from NetworkConfigurationTest
[ RUN      ] NetworkConfigurationTest.ConfigurationConstructionTest
[       OK ] NetworkConfigurationTest.ConfigurationConstructionTest (0 ms)
[ RUN      ] NetworkConfigurationTest.ConfigurationFieldsTest
[       OK ] NetworkConfigurationTest.ConfigurationFieldsTest (0 ms)
[----------] 2 tests from NetworkConfigurationTest (0 ms total)

[----------] 1 test from NetworkConnectionTest
[ RUN      ] NetworkConnectionTest.CreateCloseConnectionTest
[       OK ] NetworkConnectionTest.CreateCloseConnectionTest (4 ms)
[----------] 1 test from NetworkConnectionTest (4 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 3 test suites ran. (10 ms total)
[  PASSED  ] 4 tests.
```
