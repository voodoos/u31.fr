import React from "react"
import { graphql } from "gatsby"
//import Img from "gatsby-image"
const Layout = require('../components/layout/Layout.bs.js').make;
const PhotoGrid = require('../components/layout/gallery/PhotoGrid.bs.js').make;

export default ({ data }) => {
    console.log(data);
    return (< Layout >
        <PhotoGrid photos={data.allFile.edges} />
        {/*  <div className="grid">
            <div className="grid-item" id="test" style={{ "width": "200px" }} onClick={() => document.getElementById("test").style.setProperty("width", "100%")}>
                <Img fluid={data.allFile.edges[0].node.childImageSharp.fluid} />
            </div>
        </div>*/}
    </Layout >)
}

export const query = graphql`
query MyQuery {
    allFile(filter: {sourceInstanceName: {eq: "origami"}}) {
      edges {
        node {
          childImageSharp {
            fluid(maxWidth: 1900, fit: COVER){
              ...GatsbyImageSharpFluid_withWebp_tracedSVG
              presentationWidth
            }
            fixed(width: 200, height: 200){
              ...GatsbyImageSharpFixed_withWebp_tracedSVG
            }
          }
        }
      }
    }
  }
`;