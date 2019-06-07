var child_process = require('child_process');

// Start BSB when running gatsby develop
exports.onCreateDevServer = ({ app }) => {
    console.log("Starting bsb process.")

    var bsb = child_process.spawn('node_modules/.bin/bsb', ['-make-world', '-w']);

    bsb.stdout.on('data', function (data) {
        console.log('bsb: ' + data.toString());
    });

    bsb.stderr.on('data', function (data) {
        console.log('bsb err: ' + data.toString());
    });

    bsb.on('exit', function (code) {
        console.log('bsb process exited with code ' + code.toString());
    });
    /*
        child_process.exec('node_modules/.bin/bsb', function (err, stdout, stderr) {
            if (err) {
                console.log(
                    "Child processes failed with error code: " +
                    err.code);
            }
            console.log(stdout, stderr);
        });*/
}

// Remove .bs from pages names
exports.onCreatePage = async (
    { page, actions: { createPage, deletePage } },
    { derivePathFromComponentName }
) => {
    var path = page.path
    var newPage = { ...page };

    path = path.replace('.bs/', '/')
    path = path.replace('_', '-')
    if (path == '/index/') path = '/'

    if (page.path != path) {
        deletePage(page)
        console.log(`Changed path '${page.path}' to '${path}'.`)
        createPage({ ...page, path })
    }
}