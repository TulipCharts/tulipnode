{
  "targets": [
    {
      "target_name": "tulind",
      "sources": ["tulind.cpp", "tiamalgamation.c"],
      "include_dirs": [ "<!(node -e \"require('nan')\")" ]
    }
  ]
}
