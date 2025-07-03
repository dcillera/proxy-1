
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

OPENSSL_DISABLED_EXTENSIONS = [
            "envoy.tls.key_providers.cryptomb",
            "envoy.tls.key_providers.qat",
            "envoy.quic.deterministic_connection_id_generator",
            "envoy.quic.crypto_stream.server.quiche",
            "envoy.quic.proof_source.filter_chain",
        ]

def load_envoy():
    http_archive(
        name = "envoy",
        sha256 = "ac614e571fe7ed6cf333b4db3eae49ce56d3d5313dd12571eac51a2869471646",
        strip_prefix = "envoy-openssl-2dac23cd4b95f9a243c36e22b4710df980dd51f0",
        url = "https://github.com/dcillera/envoy-openssl/archive/2dac23cd4b95f9a243c36e22b4710df980dd51f0.tar.gz",
        patch_args = ["-p1"],
        patches = [
            "@io_istio_proxy//ossm/patches:use-cmake-from-host.patch",
            ],
    )
