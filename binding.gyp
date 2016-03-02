{'targets': [{
    'target_name': 'portreset',
#    'conditions': [ ['OS=="linux"', { 'libraries': [ '-lX11','-lXfixes' ] }]],
    'include_dirs': [
        "<!(node -e \"require('nan')\")"
    ],
    'sources': [ 'binding.cc' ],
}]}
